//
// Created by tonytech on 16.8.2025.
//
#include <iostream>
#include <vector>
#include "Defines.h"

using namespace std;

auto parsShort(const char *rawDataBytes, const char *rawDataBytesEnd, long long &result) -> ErrorCode {
    if (rawDataBytesEnd - rawDataBytes < sizeof(short))
        return PARSE_FAILURE; // not enough buffer

    // (short *) rawDataBytes => type cast: “treat rawDataBytes as a pointer to short”.
    // *((short *) rawDataBytes) => gives you the actual short value stored at the beginning of rawDataBytes.
    // result = *((short *) rawDataBytes);
    result = *reinterpret_cast<const short *>(rawDataBytes);
    return PARSE_SUCCESS;
}

auto parsInt(const char *rawDataBytes, const char *rawDataBytesEnd, long long &result) -> ErrorCode {
    if (rawDataBytesEnd - rawDataBytes < sizeof(int))
        return PARSE_FAILURE; // not enough buffer

    result = *reinterpret_cast<const int *>(rawDataBytes);
    return PARSE_SUCCESS;
}

auto parsLong(const char *rawDataBytes, const char *rawDataBytesEnd, long long &result) -> ErrorCode {
    if (rawDataBytesEnd - rawDataBytes < sizeof(long))
        return PARSE_FAILURE; // not enough buffer

    result = *reinterpret_cast<const long *>(rawDataBytes);
    return PARSE_SUCCESS;
}

auto parseData(const string &commands, const char *rawDataBytes, const size_t rawDataBytesCount,
               std::vector<long long> &outParsedNumbers) -> ErrorCode {
    if (rawDataBytesCount == 0 || commands.empty())
        return PARSE_EMPTY;

    const char *rawDataBytesEnd = rawDataBytes + rawDataBytesCount;
    ErrorCode resultErrorCode = PARSE_SUCCESS;

    for (const char command: commands) {
        long long parsedNumber = 0;

        switch (command) {
            case 's':
                resultErrorCode = parsShort(rawDataBytes, rawDataBytesEnd, parsedNumber);
                rawDataBytes += sizeof(short);
                break;
            case 'i':
                resultErrorCode = parsInt(rawDataBytes, rawDataBytesEnd, parsedNumber);
                rawDataBytes += sizeof(int);
                break;
            case 'l':
                resultErrorCode = parsLong(rawDataBytes, rawDataBytesEnd, parsedNumber);
                rawDataBytes += sizeof(long);
                break;
            default:
                break;
        }

        if (resultErrorCode != PARSE_SUCCESS)
            return resultErrorCode;

        outParsedNumbers.push_back(parsedNumber);
    }

    return resultErrorCode;
}

void printResult(const ErrorCode errorCode, const vector<long long> &parsedNumbers) {
    switch (errorCode) {
        case 0:
            for (const long long parsedNumber: parsedNumbers)
                cout << parsedNumber << " ";
            cout << endl;
            break;
        case 1:
            for (const long long parsedNumber: parsedNumbers)
                cout << parsedNumber << " ";
            cout << "Warning, buffer underflow detected" << endl;
            break;
        case 2:
            cout << "No input provided" << endl;
            break;
        default:
            break;
    }
}
