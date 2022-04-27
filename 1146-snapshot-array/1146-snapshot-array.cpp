class SnapshotArray {
public: map<int, map<int, int>> m;
    int snapid = 0;
        
    SnapshotArray(int length) {
        for(int i =0;i< length;i++){
          map<int, int> tmp; 
            tmp[0] = 0;
            m[i] = tmp;
        }
    }
    
    void set(int index, int val) {
        m[index][snapid]=val;
    }
    
    int snap() {
       return snapid++;
    }
    
    int get(int index, int snap_id) {
        auto it = m[index].upper_bound(snap_id);
        return it == begin(m[index]) ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */