#ifdef __cplusplus
extern "C" {
#endif
char* strcpy(char*, const char*);
int strcmp(const char*, const char*);
int strlen(const char*);
// ...
#ifdef __cplusplus
}
#endif

extern "C" {    // 可以放置任何声明，例如：
int g1;         // 定义
extern int g2;  // 声明，非定义
}

extern "C" int g3;  // 声明，非定义
extern "C" {
int g4;  // 定义
}