Level1 = {
    textures = {
        [0] = { id = "jungle", file = "tilemaps/jungle.png" },
        [1] = { id = "bat", file = "images/bat.png" },
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
            layer = 1,
            components = {
                rect_transform = {
                    draw_rect = {
                        x = 300,
                        y = 100,
                        width = 64,
                        height = 64
                    },
                },
                animated_sprite_renderer = {
                    texture_id = "bat",
                    animations = {
                      [0] = {
                         name = "down",
                         frames = {
                            [0] = { x = 0, y = 0, width = 32, height = 32 },
                            [1] = { x = 32, y = 0, width = 32, height = 32 },
                            [2] = { x = 64, y = 0, width = 32, height = 32 },
                            [3] = { x = 96, y = 0, width = 32, height = 32 }
                         },
                      },
                      [1] = {
                        name= "right",
                        frames = {
                            [0] = { x = 0, y = 32, width = 32, height = 32 },
                            [1] = { x = 32, y = 32, width = 32, height = 32 },
                            [2] = { x = 64, y = 32, width = 32, height = 32 },
                            [3] = { x = 96, y = 32, width = 32, height = 32 }
                        }
                      },
                      [2] = {
                        name = "up",
                        frames = {
                          [0] =  { x = 0, y = 64, width = 32, height = 32 },
                           [1] =  { x = 32, y = 64, width = 32, height = 32 },
                            [2] = { x = 64, y = 64, width = 32, height = 32 },
                            [3] = { x = 96, y = 64, width = 32, height = 32 }
                        }
                      },
                      [3] = {
                        name = "left",
                        frames = {
                          [0] =  { x = 0, y = 96, width = 32, height = 32 },
                           [1] =  { x = 32, y = 96, width = 32, height = 32 },
                            [2] = { x = 64, y = 96, width = 32, height = 32 },
                            [3] = { x = 96, y = 96, width = 32, height = 32 }
                        }
                   },
                   },
                },
                collider = {
                    tag = "PLAYER"
                },
                rigid_body_2d = {

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
            layer = 1,
            components = {
                rect_transform = {
                    draw_rect = {
                        x = 650,
                        y = 405,
                        width = 64,
                        height = 64,
                    }
                },
                sprite_renderer = {
                    texture_id = "tank",
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
