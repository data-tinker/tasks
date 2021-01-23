class Solution {
private:
    enum State {
        LOCAL,
        DROP,
        DOMAIN
    };
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> localAndDomainName;

        for (auto& email : emails) {
            string localName;
            string domainName;
            State state = LOCAL;

            for (const auto c : email) {
                if (c == '+') {
                    state = DROP;
                } else if (c == '@') {
                    state = DOMAIN;
                } else if (state == LOCAL) {
                    if (c != '.') {
                        localName += c;
                    }
                } else if (state == DOMAIN) {
                    domainName += c;
                }
            }

            localAndDomainName.insert(localName + '@' + domainName);
        }

        return localAndDomainName.size();
    }
};
