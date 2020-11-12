# https://leetcode.com/problems/design-parking-system/
class ParkingSystem:
    def __init__(self, big: int, medium: int, small: int):
        self.capacity = [big, medium, small]
        self.used = [0, 0, 0]

    def addCar(self, carType: int) -> bool:
        if self.used[carType - 1] < self.capacity[carType - 1]:
            self.used[carType - 1] += 1
            return True
        return False
        


# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)
