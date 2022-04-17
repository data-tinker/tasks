class Solution {
  class DSU {
    int[] parent, rank;

    public DSU(int n) {
      parent = new int[n];
      rank = new int[n];
      for (int i = 0; i < n; i++) {
        parent[i] = i;
      }
    }

    public int find(int a) {
        if (a != parent[a]) {
            parent[a] = find(parent[a]);
        }

        return parent[a];
    }

    public void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) {
            return;
        } else if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        } else if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
        } else {
            parent[pa] = pb;
            ++rank[pb];
        }
  	}

    public void unUnion(int a) {
      parent[a] = a;
      rank[a] = 0;
    }
  }

  public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
	Map<Integer, List<Integer>> timeToMeetingIdxs = new TreeMap<>();
    for (int i = 0; i < meetings.length; ++i) {
      List<Integer> meetingIdxs = timeToMeetingIdxs.getOrDefault(meetings[i][2], new ArrayList<>());
      meetingIdxs.add(i);
      timeToMeetingIdxs.put(meetings[i][2], meetingIdxs);
    }

    System.out.println(timeToMeetingIdxs);

    DSU dsu = new DSU(n);
    dsu.union(0, firstPerson);

    for (var entry : timeToMeetingIdxs.entrySet()) {
      Set<Integer> participants = new HashSet<>();

      for (int idx : entry.getValue()) {
        dsu.union(meetings[idx][0], meetings[idx][1]);
        participants.add(meetings[idx][0]);
        participants.add(meetings[idx][1]);
      }

      for (int participant : participants) {
        if (dsu.find(participant) != dsu.find(0)) {
          dsu.unUnion(participant);
        }
      }
    }

    List<Integer> result = new ArrayList<>();
    for (int i = 0; i < n; ++i) {
      if (dsu.find(i) == dsu.find(0)) {
        result.add(i);
      }
    }

    return result;
  }
}
