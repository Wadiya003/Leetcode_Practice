class Solution {
public:
    string convert(string s, int numRows) {
      if(numRows<2)return s;
       bool direction=true;

        int row=0;
        string v[numRows];
        for(int i=0;i<s.size();i++){
         v[row].push_back(s[i]);
            if(row==0){
            direction=true;}
            else if(row==numRows-1){
                direction=false;
            }
            if(direction){
                row+=1;
            }
            else if(!direction){
                row-=1;
            }
        }
        s.clear();
        for(int i=0;i< numRows;i++){
            s+=v[i];
        }
        return s;
        
    }
};
//  if(num<2)
//         {
//             return s;
//         }
//         int size=s.size();
//         int row=0;
//         bool dir=true;
//        string v[num];
//         for(int i=0;i<s.size();i++)
//         {
//            v[row].push_back(s[i]);
//             if(row==0)
//             {
//                 dir=true;
//             }
//             else if(row==num-1)
//             {
//                 dir=false;
                
//             }
//             if(dir)
//             {
//                 row+=1;
//             }
//             else if(!dir)
//             {
//                 row-=1;
//             }
            
//         }
//         s.clear();
//         {
//             for(int i=0;i<num;i++)
//             {
//                 s+=v[i];
//             }
//         }
//         return s;
        
//     }

     
    