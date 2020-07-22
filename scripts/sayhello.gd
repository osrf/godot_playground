extends SceneTree

func _init():

    var s = Summator.new()
    s.add(10)
    s.add(20)
    s.add(30)
    print(s.get_total())
    s.reset()

    print("Hello!")
    quit()
