#ifndef ZB_FIND_EMAIL_RESPONSE_H
#define ZB_FIND_EMAIL_RESPONSE_H

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * @brief highlights how a domain can format its emails and how confident is
 * the API about it
 */
class ZBDomainFormat {

public:
    std::string format;
    std::string confidence;

    static ZBDomainFormat from_json(const json& json_obj);

    bool operator==(const ZBDomainFormat& other) const;
};

/**
 * @brief The class associated with the GET /guessformat request.
 *
 */
class ZBFindEmailResponse {

public:
    std::string email;
    std::string domain;
    std::string format;
    std::string status;
    std::string subStatus;
    std::string confidence;
    std::string didYouMean;
    std::string failureReason;
    std::vector<ZBDomainFormat> otherDomainFormats;

    static ZBFindEmailResponse from_json(const json& json_obj);

    bool operator==(const ZBFindEmailResponse& other) const;
};



#endif