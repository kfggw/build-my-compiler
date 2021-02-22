#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

enum TokenKind{
  NUM = 256,
  IF,
  ELIF,
  ELSE,
  FOR,
  WHILE,
  DEF,
  RETURN,
  ID
};

void ResetBuf(char *buf, int size) {
  for(int i = size - 1; i >=0; --i) {
    buf[i] = '\0';
  }
}

/**
 * 获取下一个Token
 * @return Token对应的类别
 */
int GetNextToken() {
  static char lastChar = ' ';
  static char buf[128] = {'\0'};
  static int index = 0;

  // 读取空白
  while(isspace(lastChar)) {
    lastChar = getchar();
  }

  // 读取到了字母, token可能为关键字或者标识符
  if(isalpha(lastChar)) {
    while(isalnum(lastChar)) {
      buf[index++] = lastChar;
      lastChar = getchar();
    }

    // 识别关键字
    if(strcmp(buf, "if") == 0) {
      ResetBuf(buf, index);
      index = 0;
      return TokenKind::IF;
    }

    if(strcmp(buf, "elif") == 0) {
      ResetBuf(buf, index);
      index = 0;
      return TokenKind::ELIF;
    }

    if(strcmp(buf, "else") == 0) {
      ResetBuf(buf, index);
      index = 0;
      return TokenKind::ELSE;
    }

    if(strcmp(buf, "for") == 0) {
      ResetBuf(buf, index);
      index = 0;
      return TokenKind::FOR;
    }

    if(strcmp(buf, "while") == 0) {
      ResetBuf(buf, index);
      index = 0;
      return TokenKind::WHILE;
    }

    if(strcmp(buf, "def") == 0) {
      ResetBuf(buf, index);
      index = 0;
      return TokenKind::DEF;
    }

    if(strcmp(buf, "return") == 0) {
      ResetBuf(buf, index);
      index = 0;
      return TokenKind::RETURN;
    }

    // 识别标识符
    ResetBuf(buf, index);
    index = 0;
    return TokenKind::ID;
  }

  // 识别数字
  if(isdigit(lastChar) || lastChar == '.') {
    while(isdigit(lastChar) || lastChar == '.') {
      buf[index++] = lastChar;
      lastChar = getchar();
    }

    double val = atof(buf);
    ResetBuf(buf, index);
    index = 0;
    return TokenKind::NUM;
  }

  // 其他情况
  ResetBuf(buf, index);
  index = 0;
  return lastChar;
}

int main() {
  while(1) {
    int tokenKind = GetNextToken();
    printf("TokenKind: %d\n", tokenKind);
  }

  return 0;
}
