#include <sstream>

#include "ZeroBounce/utils.h"
#include "ZeroBounce/ZBCreditsResponse.h"

std::string ZBCreditsResponse::toString()
{
    std::stringstream stringStream;
    stringStream << "ZBCreditsResponse{" <<
                "credits='" << credits << '\'' <<
                '}';

    return stringStream.str();
}

ZBCreditsResponse ZBCreditsResponse::from_json(const json& j) {
    ZBCreditsResponse r;

    r.credits = std::stoi(getOrDefault<std::string>(j, "Credits", "-1"));

    return r;
}

bool ZBCreditsResponse::operator==(const ZBCreditsResponse& other) const {
    return credits == other.credits;
}