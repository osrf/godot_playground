extends SceneTree

var time_elapsed = 0
var keys_typed = []
var quit = false

func _init():
    print("init")
    # quit()

func _initialize():
    print("Initialized:")
    print("  Starting time: %s" % str(time_elapsed))

    var sceneLoader = SceneLoader.new()
    get_root().add_child(sceneLoader)
    print("Added SceneLoader!")

    sceneLoader.Init()
    sceneLoader.CreateCamera()
    sceneLoader.CreateLight()
    sceneLoader.CreateSphere()

    # uncomment to create objects using gdscript
    # # create sphere
    # var s = SphereMesh.new()
    # var mi = MeshInstance.new()
    # mi.set_mesh(s)
    # mi.set_translation(Vector3(0, 0, -5))
    # get_root().add_child(mi)


    # # create camera
    # var camera = Camera.new()
    # get_root().add_child(camera)
    # # camera.make_current()
    # print(camera.is_inside_tree())

    # # create light
    # var light = DirectionalLight.new()
    # get_root().add_child(light)
    # print(light.is_inside_tree())


func _idle(delta):
    time_elapsed += delta
    # Return true to end the main loop.
    if quit:
      quit()

func _input_event(event):
    # Record keys.
    if event is InputEventKey and event.pressed and !event.echo:
        keys_typed.append(OS.get_scancode_string(event.scancode))
        # Quit on Escape press.
        if event.scancode == KEY_ESCAPE:
            quit = true
    # Quit on any mouse click.
    if event is InputEventMouseButton:
        quit = true

func _finalize():
    print("Finalized:")
    print("  End time: %s" % str(time_elapsed))
    print("  Keys typed: %s" % var2str(keys_typed))
