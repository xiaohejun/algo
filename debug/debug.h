#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

void __print(int x) {std::cout << x;}
void __print(long x) {std::cout << x;}
void __print(long long x) {std::cout << x;}
void __print(unsigned int x) {std::cout << x;}
void __print(unsigned long x) {std::cout << x;}
void __print(unsigned long long x) {std::cout << x;}
void __print(float x) {std::cout << x;}
void __print(double x) {std::cout << x;}
void __print(long double x) {std::cout << x;}
void __print(char x) {std::cout << '\'' << x << '\'';}
void __print(const char *x) {std::cout << '\"' << x << '\"';}
void __print(const std::string &x) {std::cout << '\"' << x << '\"';}
void __print(bool x) {std::cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const std::pair<T, V> &x) {std::cout << '('; __print(x.first); std::cout << ", "; __print(x.second); std::cout << ')';}

template<typename T>
void __print(const T &x) {int f = 0; std::cout << '['; for (auto &i: x) std::cout << (f++ ? ", " : ""), __print(i); std::cout << "]";}

void _print() {std::cout << "\n";}

template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) std::cout << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
    #define dbg(x...) std::cout << "[line " << __LINE__ << "]: " << #x << " = "; _print(x);
#else
    #define dbg(x...)
#endif

#endif