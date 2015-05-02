Basic Arkanoid.

`git clone && make`

    Entity System:
        Everything is an Entity, even specials vars like player (player.vertex)

        An Entity is defined over a few types :
            Vertex2f (point or direction), Vertex3f(circle), Vertex4f(quads)
        To keep it consistent, you need to addEntity(t_Entity) if you wish to add something into the global entity iterator.

