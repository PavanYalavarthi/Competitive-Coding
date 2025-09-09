int maximizingXor(int l, int r) {
    if(l == r) return 0;
    int i = 31 - __builtin_clz(r);
    for(; i >= 0; i--) {
        if((l & (1 << i)) != (r & (1 << i))) break;
    }
    i++;
    return (1 << i) - 1;
}