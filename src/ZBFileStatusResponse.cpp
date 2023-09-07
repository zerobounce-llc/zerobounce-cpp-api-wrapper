#include <sstream>

#include "ZeroBounce/utils.h"
#include "ZeroBounce/ZBFileStatusResponse.h"

std::string ZBFileStatusResponse::toString()
{
    std::stringstream stringStream;
    stringStream << "ZBFileStatusResponse{" <<
                "success=" << success <<
                ", message='" << message << '\'' <<
                ", fileId='" << fileId << '\'' <<
                ", fileName='" << fileName << '\'' <<
                ", uploadDate='" << uploadDate << '\'' <<
                ", fileStatus='" << fileStatus << '\'' <<
                ", completePercentage='" << completePercentage << '\'' <<
                ", returnUrl='" << returnUrl << '\'' <<
                ", errorReason='" << errorReason << '\'' <<
                '}';

    return stringStream.str();
}

ZBFileStatusResponse ZBFileStatusResponse::from_json(const json& j) {
    ZBFileStatusResponse r;

    r.success = getOrDefault<bool>(j, "success", false);
    r.message = getOrDefault<std::string>(j, "message", "");
    r.errorReason = getOrDefault<std::string>(j, "error_reason", "");
    r.fileId = getOrDefault<std::string>(j, "file_id", "");
    r.fileName = getOrDefault<std::string>(j, "file_name", "");
    r.uploadDate = getOrDefault<std::string>(j, "upload_date", "");
    r.fileStatus = getOrDefault<std::string>(j, "file_status", "");
    r.completePercentage = getOrDefault<std::string>(j, "complete_percentage", "");
    r.returnUrl = getOrDefault<std::string>(j, "return_url", "");

    return r;
}

bool ZBFileStatusResponse::operator==(const ZBFileStatusResponse& other) const {
    return success == other.success &&
        message == other.message &&
        errorReason == other.errorReason &&
        fileId == other.fileId &&
        fileName == other.fileName &&
        uploadDate == other.uploadDate &&
        fileStatus == other.fileStatus &&
        completePercentage == other.completePercentage &&
        returnUrl == other.returnUrl;
}