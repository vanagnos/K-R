#include <stdio.h>
#include <ctype.h>

int strindex(const char *s, char *t) {
      int index = 0;
      int pos = -1;

      while (*s != '\0'){
          if (*s == *t){
              const char *s_temp = s;
              const char *t_temp = t;

              while (*s_temp != '\0' && *t_temp != '\0' && *s_temp == *t_temp){
                  s_temp++;
                  t_temp++;
              }

              if (*t_temp == '\0'){
                  pos = index;
                  break;
              }
          }
          s++;
          index++;
      }
      return pos;
}

int main(){
    char s[] = "hello world";
    char t[] = "world";

    printf("%d\n", strindex(s, t));  /* Expected output: 6 */
    return 0;
}
