FROM ubuntu:latest

WORKDIR /home/root

RUN apt upgrade && apt update

RUN apt install -y libopus0 libopus-dev libsodium23 wget build-essential cmake

RUN wget -O dpp.deb https://github.com/brainboxdotcc/DPP/releases/download/v10.0.30/libdpp-10.0.30-linux-rpi-arm64.deb
RUN dpkg -i dpp.deb

RUN apt install -y libsndfile-dev libboost-all-dev

RUN apt install -y software-properties-common
RUN apt update

RUN add-apt-repository universe
RUN apt update
RUN apt install -y libfmt-dev

COPY . /home/root/snippy
WORKDIR /home/root/snippy

CMD [ "bash" ]
