void fusion (int *a, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
}
 
void tri_fusion (int *liste, int taille) {
    if (taille < 2) return;
    int milieu = taille / 2;
    tri_fusion(liste, milieu);
    tri_fusion(liste milieu, taille - milieu);
    fusion(liste, taille, milieu);
}
