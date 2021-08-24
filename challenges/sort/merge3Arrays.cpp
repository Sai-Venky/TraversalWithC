// merge3Arrays

vector<int> merge3Arrays(vector<int>& a, vector<int>& b, vector<int>& c)
{
    vector<int> res;
    for(int ai = 0, bi = 0, ci = 0; ai < a.size() || bi < b.size() || ci < c.size();)
    {
        int m = min({ ai < a.size() ? a[ai] : INT_MAX, bi < b.size() ? b[bi] : INT_MAX, ci < c.size() ? c[ci] : INT_MAX});
        res.push_back(m);
        if(a[ai]==m) ++ai;
        if(b[bi]==m) ++bi;
        if(c[ci]==m) ++ci;
    }
    return res;
}

vector<int> merge3Arrays(vector<int>& a, vector<int>& b, vector<int>& c)
{
    vector<int> res;
    int ia = 0, ib = 0, ic = 0;
    while(ia < a.size() || ib < b.size() || ic < c.size())
    {
        pair<int, int*> p(0, NULL);
        if(ia < a.size()) p = {a[ia], &ia}; 
        if(ib < b.size() && (!p.second || b[ib] < p.first)) p = {b[ib], &ib};
        if(ic < c.size() && (!p.second || c[ic] < p.first)) p = {c[ic], &ic};
        if(res.empty() || res.back() != p.first) res.push_back(p.first);
        ++*p.second;
    }
    return res;
}