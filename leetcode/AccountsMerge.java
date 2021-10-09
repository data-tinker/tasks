class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String, String> emailToName = new HashMap();
        Map<String, ArrayList<String>> graph = new HashMap();

        for (List<String> account : accounts) {
            String name = account.get(0);

            for (int i = 1; i < account.size(); ++i) {
                String email = account.get(i);

                graph.computeIfAbsent(email, x -> new ArrayList<String>()).add(account.get(1));
                graph.computeIfAbsent(account.get(1), x -> new ArrayList<String>()).add(email);
                emailToName.put(email, name);
            }
        }

        Set<String> seen = new HashSet();
        List<List<String>> result = new ArrayList();

        for (String email: graph.keySet()) {
            if (!seen.contains(email)) {
                seen.add(email);
                Stack<String> stack = new Stack();
                stack.push(email);
                List<String> component = new ArrayList();

                while (!stack.empty()) {
                    String node = stack.pop();
                    component.add(node);
                    for (String nb: graph.get(node)) {
                        if (!seen.contains(nb)) {
                            seen.add(nb);
                            stack.push(nb);
                        }
                    }
                }

                Collections.sort(component);
                component.add(0, emailToName.get(email));
                result.add(component);
            }
        }

        return result;
    }
}
