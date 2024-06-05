#include "audioMaker.h"

AudioMaker::AudioMaker() {
  this->audios["turi"] = this->turi();
  this->audios["ip"] = this->ip();
}

AudioMaker::~AudioMaker() {}

std::pair<float*, int> AudioMaker::openFile(std::string path) {
  SF_INFO info;
  SNDFILE* file = sf_open(path.c_str(), SFM_READ, &info);

  if(!file){
    throw std::runtime_error(fmt::format("File {} not found!", path));
  }

  int bufferSize = info.frames * info.channels;
  float* buffer = new float[bufferSize];
  sf_readf_float(file, buffer, info.frames);

  sf_close(file);
  return std::pair<float*, int>(buffer, bufferSize);
}

std::pair<float*, int> AudioMaker::turi() {
  return this->openFile("res/turi.wav");
}

std::pair<float*, int> AudioMaker::ip() {
  return this->openFile("res/ip.wav");
}

std::vector<float> AudioMaker::cleanUp(std::vector<float> audioData) {
  std::vector<float> cleaned;
  int zeros = 0;

  for(float sample: audioData) {
    if(sample == 0.0) {
      zeros += 1;
    } else {
      zeros = 0;
    }

    if(zeros <= 4000 || sample != 0.0) {
      cleaned.push_back(sample);
    }
  } 

  return cleaned;
}

void AudioMaker::writeFile(std::vector<float> audioData, std::string filename) {
  SF_INFO fileInfo;
  fileInfo.frames = audioData.size();
  fileInfo.samplerate = 44100;
  fileInfo.channels = 2;
  fileInfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

  SNDFILE* outfile = sf_open(filename.c_str(), SFM_WRITE, &fileInfo);
  if(!outfile) {
    sf_close(outfile);
    throw std::runtime_error("Couldn't create file!");
  }

  sf_count_t count = sf_write_float(outfile, audioData.data(), audioData.size());
  if(count != audioData.size()) {
    sf_close(outfile);
    throw std::runtime_error("Error writing audio data!");
  }

  sf_close(outfile);
}

void AudioMaker::makeTuriIp(std::vector<std::string>* lyrics, std::string filename) {
  std::vector<float> audioData;

  for(std::string lyric: *lyrics) {
    std::pair<float*, int> audio = this->audios[lyric];

    for(int i = 0; i < audio.second; i++) {
      audioData.push_back(audio.first[i]);
    }
  }

  audioData = this->cleanUp(audioData);
  this->writeFile(audioData, filename);
}