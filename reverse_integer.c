int reverse(int x){
    int negative = 0;
    int reverse = 0;
    
    if (x < -1 * INT_MAX) {
        return 0;
    }
    
    if (x < 0) {
        negative = 1;
        x = ~(x - 1);
    }
    
    while (x > 0) {
        int lastDigit = x % 10;
        if (reverse > 0 && INT_MAX / reverse < 10) {
            return 0;
        }
        reverse = (reverse * 10) + lastDigit;
        x = x / 10;
    }
    
    if (negative) {
        reverse = ~reverse + 1;
    }
    
    return reverse;
}
