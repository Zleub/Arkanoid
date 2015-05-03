Basic Arkanoid.

`git clone && make`

    Entity System:
        Everything is an Entity, even specials vars like player (player.vertex)

        An Entity is defined over a few types :
            Vertex2f (point or direction), Vertex3f(circle), Vertex4f(quads)
        To keep it consistent, you need to addEntity(t_entity) if you wish to add something into the global entity iterator.

        In order to use an Entity, you can check the type against :
        enum                        e_types
        {
            V2,
            V3,
            V4
        };

        And use the content as Vertex type :
        {
            t_entitylist *List;
            t_entity     *Entity;

            Entity = List.content;
            if (List.type == V2)
                Entity.x || Entity.y
            if (List.type == V3)
                Entity.x || Entity.y || Entity.radius
            if (List.type == V2)
                Entity.x || Entity.y || Entity.width || Entity.height
        }

