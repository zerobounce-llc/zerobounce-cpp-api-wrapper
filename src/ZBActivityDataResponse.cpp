#include <sstream>

#include "ZeroBounce/utils.h"
#include "ZeroBounce/ZBActivityDataResponse.h"

std::string ZBActivityDataResponse::toString()
{
    std::stringstream stringStream;
    stringStream << "ZBActivityDataResponse{" <<
                "found=" << found <<
                ", activeInDays='" << activeInDays << '\'' <<
                ", error='" << error << '\'' <<
                '}';

    return stringStream.str();
}

ZBActivityDataResponse ZBActivityDataResponse::from_json(const json& j) {
    ZBActivityDataResponse r;

    r.found = getOrDefault<bool>(j, "found", false);
    r.activeInDays = std::stoi(getOrDefault<std::string>(j, "active_in_days", "-1"));
    r.error = getOrDefault<std::string>(j, "error", "");

    return r;
}

bool ZBActivityDataResponse::operator==(const ZBActivityDataResponse& other) const {
    return found == other.found &&
        activeInDays == other.activeInDays &&
        error == other.error;
}