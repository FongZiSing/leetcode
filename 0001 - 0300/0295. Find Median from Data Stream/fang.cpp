class MedianFinder {
    vector<int> data;

public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        if (data.empty())
            data.push_back(num);
        else
            data.insert(lower_bound(data.begin(), data.end(), num), num);
    }

    double findMedian() {
        int size = data.size();
        int mid = size / 2;
        return size & 1 ? data[mid] : (data[mid] + data[mid - 1]) * 0.5;
    }
};
