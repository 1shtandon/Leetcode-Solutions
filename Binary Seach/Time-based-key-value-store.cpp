class TimeMap
{
public:
    unordered_map<string, vector<pair<string, int>>> dataStructure;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        dataStructure[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp)
    {
        int start = 0;
        int end = dataStructure[key].size() - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            int time = dataStructure[key][mid].second;

            if (time == timestamp)
            {
                return dataStructure[key][mid].first;
            }
            else if (timestamp < time)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        if (end >= 0 and end < dataStructure[key].size())
        {
            return dataStructure[key][end].first;
        }
        return "";
    }
};