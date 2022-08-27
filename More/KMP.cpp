
void fillLps(string pat, int lps[], int m)
    {
        lps[0] = 0;
        int i=1;
        int len = 0;
        while(i<m)
        {
            if(pat[i] == pat[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len == 0){
                    lps[i] = 0;
                    i++;
                }
                else
                   len = lps[len-1];
            }
        }
    }
    int KMP(string txt, string pat) {
      
        int n = txt.length();
        int m = pat.length();
        if(m == 0)
            return 0;
        if(n == 0 || (n<m))
            return -1;
        int lps[m];
        fillLps(pat,lps,m);
        int i=0,j=0;
        while(i<n)
        {
            if(txt[i] == pat[j])
            {
                i++;
                j++;
            }
            if(j == m)
            {
                cout<<(i-j);
              // decide from which j should be matched the next character
                j = lps[j-1];
            }
               
            else if((i<n) && (pat[j] != txt[i]))
            {
                if(j == 0)
                    i++;
                else
                    j = lps[j-1];
            }
        }
        return -1;
    }
