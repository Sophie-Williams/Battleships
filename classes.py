class coordinate:
	x = 0
	y = 0

class ship:
	pos = coordinate()

	def __init__(self, n):
		self.size = n

	def player(self, x, y):
		self.pos.x = x
		self.pos.y = y

	def bot(self):
		self.pos.x = 5
		self.pos.y = 5

	def showpos(self):
		print self.pos.x, self.pos.y