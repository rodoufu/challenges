# https://leetcode.com/problems/throne-inheritance/
class ThroneInheritance:
    def __init__(self, kingName: str):
        self.king = kingName
        self.person_children: Dict[str, Set[str]] = {}
        # self.person_parent: Dict[str, str] = {}
        self.dead: Set[str] = set()
        self.person_age: Dict[str, int] = {kingName: 0}
        self.age = 1

    def birth(self, parentName: str, childName: str) -> None:
        self.person_children[parentName] = self.person_children.get(parentName, set())
        self.person_children[parentName].add(childName)
        # self.person_parent[childName] = parentName
        self.person_age[childName] = self.age
        self.age += 1

    def death(self, name: str) -> None:
        self.dead.add(name)
        # parent = self.person_parent[name]
        # self.person_children[parent].remove(name)
        
    def successors(self, name: str) -> Iterable[str]:
        if name not in self.dead:
            yield name
        for child in sorted(self.person_children.get(name, []), key=lambda x: self.person_age[x]):
            for successor in self.successors(child):
                yield successor

    def getInheritanceOrder(self) -> List[str]:
        return list(self.successors(self.king))


# Your ThroneInheritance object will be instantiated and called as such:
# obj = ThroneInheritance(kingName)
# obj.birth(parentName,childName)
# obj.death(name)
# param_3 = obj.getInheritanceOrder()
