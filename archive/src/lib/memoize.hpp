#ifndef MEMOIZE_HPP
#define MEMOIZE_HPP

#include <map>
#include <tuple>
#define MEMOIZATOR(N, R, ...)                               \
  R _ ## N (__VA_ARGS__);                                   \
  std::map<std::tuple<__VA_ARGS__>, R> _memo_ ## N;         \
  template <typename ... Args>                              \
  R N (Args ... args) {                                     \
    auto& _memo = _memo_ ## N;                              \
    auto result = _memo.find(std::make_tuple(args...));     \
    if (result != _memo.end()) {                            \
      return result->second;                                \
    }                                                       \
    else {                                                  \
      auto result = _ ## N  (args...);                      \
      _memo[std::make_tuple(args...)] = result;             \
      return result;                                        \
    }                                                       \
  }                                                         \

#endif
