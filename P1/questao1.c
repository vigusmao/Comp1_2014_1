int gera_codigo(int x, int y) {
    if (x >= y) {
        return 10*x + y;
    } else {
        return y*y;
    }
}
