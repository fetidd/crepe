#pragma once

#include <string>
#include <format>
#include <expected>

enum class ErrorCode {
    UNKNOWN = 0,
    FILE_NOT_FOUND,
    INVALID_ARGUMENT,
};

class ErrorType {
public:
    std::string message;
    ErrorCode code() const {return code_;};
protected:
    ErrorCode code_ {ErrorCode::UNKNOWN};
};

class FileNotFound: public ErrorType {
public:
    FileNotFound(std::string file_path) {
        message = std::format("File {} not found!", file_path);
        code_ = ErrorCode::FILE_NOT_FOUND;
    };
};

class InvalidArgument: public ErrorType {
public:
    InvalidArgument() {
        message = "Invalid argument";
        code_ = ErrorCode::INVALID_ARGUMENT;
    }
};

bool operator== (const ErrorType &lhs, const ErrorType &rhs);

template <typename Exp> using Result = std::expected<Exp, ErrorType>;
