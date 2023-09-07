#ifndef ZBVALIDATEBATCHRESPONSE_H
#define ZBVALIDATEBATCHRESPONSE_H

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "ZeroBounce/ZBValidateResponse.h"

using json = nlohmann::json;

/**
 * Struct representing an item that is used in email batch validation
 */
struct ZBEmailToValidate {
    std::string emailAddress;
    std::string ipAddress;

    ZBEmailToValidate(const std::string& email, const std::string& ip = "")
        : emailAddress(email), ipAddress(ip) {}
};


/**
 * Model representing error from email batch validation.
 */
class ZBValidateError {
    public:
        std::string error;
        std::string emailAddress;

        std::string toString();

        static ZBValidateError from_json(const json& j);

        bool operator==(const ZBValidateError& other) const;
};

/**
 * The model used for the POST /validatebatch request.
 */
class ZBValidateBatchResponse {
    public:
        std::vector<ZBValidateResponse> emailBatch;
        std::vector<ZBValidateError> errors;

        std::string toString();

        static ZBValidateBatchResponse from_json(const json& j);

        bool operator==(const ZBValidateBatchResponse& other) const;
};

#endif