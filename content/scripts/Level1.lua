Level1 = {
    textures = {
        [0] = { id = "jungle", file = "tilemaps/jungle.png" },
        [1] = { id = "chopper", file = "images/chopper-spritesheet.png" },
        [2] = { id = "tank", file = "images/tank-big-left.png" },
        [3] = { id = "projectile", file = "images/bullet-enemy.png" },
    },
    layers = {
        [0] = { name="MAP", order=0, description="The map layer" },
        [1] = { name="GameObjects", order=1, description="The Game Objects Layer" },
        [2] = { name="UI", order=2, description="THE UI LAYER" },
    },
    map = {
        textureAssetId = "terrain-texture-day",
        file = "./assets/tilemaps/jungle.map",
        scale = 2,
        tileSize = 32,
        mapSizeX = 25,
        mapSizeY = 20
    },
    entities = {
        [0] = {
            name = "player",
            layer = 4,
            components = {
                transform = {
                    position = {
                        x = 240,
                        y = 106
                    },
                    width = 32,
                    height = 32,
                    scale = 1,
                    rotation = 0
                },
                sprite = {
                    textureAssetId = "chopper-texture",
                    animated = true,
                    frameCount = 2,
                    animationSpeed = 90,
                    fixed = false
                },
                collider = {
                    tag = "PLAYER"
                },
                input = {
                    keyboard = {
                        up = "w",
                        left = "a",
                        down = "s",
                        right = "d",
                        shoot = "space"
                    }
                }
            }
        },
        [1] = {
            name = "tank-enemy-1",
            layer = 2,
            components = {
                transform = {
                    position = {
                        x = 650,
                        y = 405
                    },
                    width = 32,
                    height = 32,
                    scale = 1,
                    rotation = 0
                },
                sprite = {
                    textureAssetId = "tank-texture-big-left",
                    animated = false
                },
                collider = {
                    tag = "ENEMY"
                },
                projectileEmitter = {
                    textureAssetId = "bullet-enemy",
                    speed = 50,
                    range = 200,
                    angle = 180
                }
            }
        }
    }
}
