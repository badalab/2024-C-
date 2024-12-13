#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[100];
    float rating;
} Movie;

int main() {
    int n;
    Movie *movies;

    printf("영화의 개수: ");
    scanf("%d", &n);

    //동적 배열 생성
    movies = (Movie *)malloc(n * sizeof(Movie));
    if (movies == NULL) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("영화 제목: ");
        scanf("%s", movies[i].title);
        printf("영화 평점: ");
        scanf("%f", &movies[i].rating);
    }

    printf("\n============\n");
    for (int i = 0; i < n; i++) {
        printf("영화 제목: %s\n", movies[i].title);
        printf("영화 평점: %.2f\n", movies[i].rating);
    }
    printf("============\n");

    free(movies);

    return 0;
}
