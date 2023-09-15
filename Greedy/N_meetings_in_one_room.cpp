int maxMeetings(int start[], int end[], int n)
{

    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++)
    {
        vec.push_back({end[i], start[i]});
    }

    sort(vec.begin(), vec.end());

    int cnt = 1, final = vec[0].first;
    for (int i = 1; i < n; i++)
    {

        if (vec[i].second > final)
        {
            cnt++;
            final = vec[i].first;
        }
    }

    return cnt;
}