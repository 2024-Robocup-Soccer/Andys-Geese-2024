void sync() {
    byte check[5];
    int shift=0;
    if(Serial2.available() > 4) {
        Serial2.readBytes(check, 5);
    }

    for (int i=0; i<5; i++) {
        if (check[i] == 255) {
            shift = i;
        }
    }

    if (shift > 0) {
        shift -= 1;
    }

    for (int i=0; i<shift; i++) {
        Serial2.read();
    }

}
