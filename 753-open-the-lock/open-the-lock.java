class Solution {
    public int openLock(String[] deadends, String target) {
        Queue<Pair<String, Integer>> q = new LinkedList<>();
        Set<String> visited = new HashSet<String>();
        Set<String> deadSet = new HashSet<String>();
        for(String s: deadends){
            deadSet.add(s);
        }

        if(deadSet.contains("0000")){
            return -1;
        }

        q.add(new Pair<>("0000", 0));
        visited.add("0000");
        int[] dx = new int[]{-1, 1};

        while(!q.isEmpty()){
            Pair<String, Integer> curr = q.poll(); //remove and element/peek together
            String currKey = curr.getKey();
            int moves = curr.getValue();

            if(currKey.equals(target)){
                return moves;
            }

            for(int i = 0; i < 4; i++){
                for(int x : dx){
                    int newDigit = (currKey.charAt(i) - '0' + x + 10) % 10;
                    String newKey = currKey.substring(0, i) + newDigit + currKey.substring(i + 1);
                    if(!visited.contains(newKey) && !deadSet.contains(newKey)){
                        visited.add(newKey);
                        q.add(new Pair<>(newKey, moves + 1));
                    }
                }
            }
        }

        return -1;
    }
}