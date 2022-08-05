/// countsetbits
int setBits(int N) {
        int count = 0;
        while(N)
        {
          // it sets rightmost setbit to zero
            N = N&(N-1);
            count++;
        }
        return count;
    }
