
    void RabinKarp(string txt,string pat)
    {
        int n1 = txt.length();
        int n2 = pat.length();
        int d = 256;
        int q = INT_MAX;
        long long hashpat = 0;
        long long hashtxt = 0;
        long long h=0;
        // The value of h would be "pow(d, M-1)%q" 
        for (int i = 1; i <= n2 - 1; i++) {
             h = (h * d) % q; 
        }
      // calculate hash for first n2 length in txt and pattern
        for(int i=0;i<n2;i++)
        {
            hashpat = (d*hashpat + pat[i])%q;
            hashtxt = (d*hashtxt + txt[i])%q;
        }
        for(int i=0;i<=n1-n2;i++)
        {
          // check if pattern matched
            if(hashpat == hashtxt)
            {
              // now compare all
                int j;
                for(j=0;j<n2;j++)
                {
                    if(txt[i+j] != pat[j])
                        break;
                }
              // if all equal then its a match
                if(j == n2)
                    cout<<i<<" ";
            }
          // compute hash for next one
            if(i< (n1-n2))
            {
                hashtxt = (d*(hashtxt-(txt[i]*h))+txt[i+n2])%q;
              // if hash becomes negative make it pos
                if(hashtxt < 0)
                    hashtxt += q;
            }
        }
    }
    
