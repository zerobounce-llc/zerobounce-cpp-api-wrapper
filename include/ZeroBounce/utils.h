#ifndef UTILS_H
#define UTILS_H

#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * Function used to get the value of a given key in a json.
 * If the key doesn't exist or it's null, a default value is returned.
 *
 * @tparam T type of the returned value
 * @param j json object
 * @param key name of the field
 * @param defaultValue default value
 * @return T value for the specified field or default value
 */
template<typename T>
T getOrDefault(json j, std::string key, T defaultValue) {
    if (j.count(key) == 0 || j[key].is_null()) {
        return defaultValue;
    }
    return j[key].get<T>();
}

#endif