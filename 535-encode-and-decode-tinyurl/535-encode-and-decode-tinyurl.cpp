class Solution {
public:
    //map<string,int> l;
    map<int,string> s;
    int count=0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        //l[longUrl]=count;
        s[count]=longUrl;
        count++;
        return to_string(count-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        return s[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));