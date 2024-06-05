#include "utils.h"

std::string snippyUtils::generateUuid() {
    boost::uuids::random_generator rg;
    boost::uuids::uuid uuid = rg();
    std::string uuidString = to_string(uuid);

    return uuidString;
}
