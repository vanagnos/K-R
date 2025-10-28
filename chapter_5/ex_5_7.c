#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <time.h> 
#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 1000 /* max length of any input line */

char *lineptr[MAXLINES]; /* pointers to text lines */
int mygetline(char *, int);
int readlines_static(char *lineptr[], int nlines, char *str);
int readlines_malloc(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void myqsort(char *lineptr[], int left, int right);

int main() {
    char storage[MAXLEN * MAXLINES];
    int nlines; /* number of input lines read */
    clock_t start, end;
    double t_malloc, t_static;

    start = clock();
    nlines = readlines_malloc(lineptr, MAXLINES);
    myqsort(lineptr, 0, nlines - 1);
    end = clock();
    t_malloc = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted output (malloc version):\n");
    writelines(lineptr, nlines);


    rewind(stdin); // reopen input to simulate same data
    printf("\nEnter same lines again (Ctrl+D to stop):\n");

    start = clock();
    nlines = readlines_static(lineptr, MAXLINES, storage);
    myqsort(lineptr, 0, nlines - 1);
    end = clock();
    t_static = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted output (static version):\n");
    writelines(lineptr, nlines);

    printf("\nTime (malloc): %.6f sec\n", t_malloc);
    printf("Time (static): %.6f sec\n", t_static);
    printf("Speedup: %.2fx faster\n", t_malloc / t_static);

    //char text_storage[MAXLEN * MAXLINES];
    //int nlines; /* number of input lines read */
    //if ((nlines = readlines(lineptr, MAXLINES, text_storage)) >= 0) {
    //    myqsort(lineptr, 0, nlines-1);
    //    writelines(lineptr, nlines);
    //    end = clock();
    //    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    //    printf("\nExecution time: %.6f seconds\n", cpu_time_used);
    //    return 0;
    //} else {
    //    printf("error: input too big to sort\n");
    //    return 1;
    //}
}

int readlines_malloc(char *lineptr[], int maxlines) {
    int len, nlines = 0;
    char *p, line[MAXLEN];

    while ((len = mygetline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        line[len - 1] = '\0';
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

int readlines_static(char *lineptr[], int maxlines, char *storage) {
    int len, nlines = 0;
    char line[MAXLEN];
    char *p = storage;

    while((len = mygetline(line, MAXLEN)) > 0){
        if (nlines >= maxlines ||  (p + len) >= (storage + MAXLINES * MAXLEN))
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[],int lim) {
     int c, i;
     for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
         s[i] = c;
     if (c == '\n') {
         s[i] = c;
         ++i;
     }
         s[i] = '\0';
         return i;
}

void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++){
        printf("%s\n", lineptr[i]);
    }
}


/* swap: interchange v[i] and v[j] */ 
void swap(char *v[], int i, int j){
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void myqsort(char *v[], int left, int right) {
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    myqsort(v, left, last-1);
    myqsort(v, left+1, right);
}

