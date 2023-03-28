#ifndef ZEROBOUNCE_H
#define ZEROBOUNCE_H

#include <functional>
#include <string>
#include <vector>

#include "ZeroBounce/ZBErrorResponse.h"
#include "ZeroBounce/ZBCreditsResponse.h"
#include "ZeroBounce/ZBGetApiUsageResponse.h"
#include "ZeroBounce/ZBValidateResponse.h"
#include "ZeroBounce/ZBValidateBatchResponse.h"
#include "ZeroBounce/ZBSendFileResponse.h"
#include "ZeroBounce/ZBFileStatusResponse.h"

template<typename T>
using OnSuccessCallback = std::function<void(T response)>;

using OnErrorCallback = std::function<void(ZBErrorResponse errorResponse)>;

struct SendFileOptions {
    std::string returnUrl = "";
    int firstNameColumn = 0;
    int lastNameColumn = 0;
    int genderColumn = 0;
    int ipAddressColumn = 0;
    bool hasHeaderRow = true;
    bool removeDuplicate = true;
};

class ZeroBounce {
    private:
        static ZeroBounce* instance;
        std::string apiKey;
        const std::string apiBaseUrl = "https://api.zerobounce.net/v2";
        const std::string bulkApiBaseUrl = "https://bulkapi.zerobounce.net/v2";
        const std::string bulkApiScoringBaseUrl = "https://bulkapi.zerobounce.net/v2/scoring";

        bool invalidApiKey(OnErrorCallback errorCallback);

        template <typename T>
        void sendRequest(
            std::string urlPath,
            OnSuccessCallback<T> successCallback,
            OnErrorCallback errorCallback
        );

        void sendFileInternal(
            bool scoring,
            std::string filePath,
            int emailAddressColumnIndex,
            SendFileOptions options,
            OnSuccessCallback<ZBSendFileResponse> successCallback,
            OnErrorCallback errorCallback
        );

        void fileStatusInternal(
            bool scoring,
            std::string fileId,
            OnSuccessCallback<ZBFileStatusResponse> successCallback,
            OnErrorCallback errorCallback
        );
    
    public:
        ZeroBounce();
        ZeroBounce(const ZeroBounce& obj) = delete;

        static ZeroBounce* getInstance();

        void initialize(std::string apiKey);

        void getCredits(
            OnSuccessCallback<ZBCreditsResponse> successCallback,
            OnErrorCallback errorCallback
        );

        void getApiUsage(
            std::tm startDate,
            std::tm endDate,
            OnSuccessCallback<ZBGetApiUsageResponse> successCallback,
            OnErrorCallback errorCallback
        );

        void validate(
            std::string email,
            std::string ipAddress,
            OnSuccessCallback<ZBValidateResponse> successCallback,
            OnErrorCallback errorCallback
        );

        void validateBatch(
            std::vector<ZBEmailToValidate> emailBatch,
            OnSuccessCallback<ZBValidateBatchResponse> successCallback,
            OnErrorCallback errorCallback
        );

        void sendFile(
            std::string filePath,
            int emailAddressColumnIndex,
            SendFileOptions options,
            OnSuccessCallback<ZBSendFileResponse> successCallback,
            OnErrorCallback errorCallback
        );

        void fileStatus(
            std::string fileId,
            OnSuccessCallback<ZBFileStatusResponse> successCallback,
            OnErrorCallback errorCallback
        );

        void getFile(
            std::string fileId,
            OnSuccessCallback<ZBSendFileResponse> successCallback,
            OnErrorCallback errorCallback
        );

        void deleteFile(
            std::string fileId,
            OnSuccessCallback<ZBSendFileResponse> successCallback,
            OnErrorCallback errorCallback
        );
};

#endif