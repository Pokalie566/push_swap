/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:26:33 by marvin            #+#    #+#             */
/*   Updated: 2024/10/18 19:26:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} Pile;

void initPile(Pile* pile, int n) {
    pile->data = (int*)malloc(n * sizeof(int));
    pile->size = n;
    pile->capacity = n;

    srand(time(NULL)); 

    for (int i = 0; i < n; i++)
    {
        pile->data[i] = rand() % 100; 
    }
}

int* merge(int* left, int sizeLeft, int* right, int sizeRight)
{
    int* result = (int*)malloc((sizeLeft + sizeRight) * sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < sizeLeft && j < sizeRight) {
        if (left[i] <= right[j]) {
            result[k++] = left[i++];
        } else {
            result[k++] = right[j++];
        }
    }
    while (i < sizeLeft) {
        result[k++] = left[i++];
    }

    while (j < sizeRight) {
        result[k++] = right[j++];
    }

    return result;
}

void triFusion(Pile* pile) {
    if (pile->size <= 1) {
        return;
    }

    int mid = pile->size / 2;
    Pile left = {pile->data, mid, mid};
    Pile right = {pile->data + mid, pile->size - mid, pile->size - mid};

    triFusion(&left);
    triFusion(&right);

    int* mergedData = merge(left.data, left.size, right.data, right.size);

    for (int i = 0; i < pile->size; i++) {
        pile->data[i] = mergedData[i];
    }
    free(mergedData);
}

int main() {
    Pile pile;
    initPile(&pile, 1000); 

    printf("Pile avant tri : ");
    for (int i = 0; i < pile.size; i++) {
        printf("%d ", pile.data[i]);
    }
    printf("\n");

    triFusion(&pile);

    printf("Pile après tri : ");
    for (int i = 0; i < pile.size; i++) {
        printf("%d ", pile.data[i]);
    }
    printf("\n");

    free(pile.data);
    return 0;
}
