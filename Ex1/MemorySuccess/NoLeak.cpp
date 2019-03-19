int main() {
    // Memory leak
    int * q = new int;
    delete q;
}
