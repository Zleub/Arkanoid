t = {}

i = -0.95
while i < 0.7 do
    table.insert(t, {
        x = 0.07 + i,
        y = 0.5,
        width = 0.15,
        type = "BRICK_OVERTIME",
        height = 0.05
    })
    i = i + 0.15
end

return t

-- return {
--     {
-- 		x = 0.07 + -0.95,
-- 		y = 0.5,
-- 		width = 0.15,
--         type = "BRICK_INFIN",
-- 		height = 0.05
--     },
--     {
-- 		x = 0.07 + -0.8,
-- 		y = 0.5,
-- 		width = 0.15,
-- 		height = 0.05,
--         type = "BRICK_INFIN"
--     },
--     {
--     	x = 0.07 + -0.65,
--     	y = 0.5,
--     	width = 0.15,
--     	height = 0.05
--     },
--     {
--     	x = 0.07 + -0.5,
--     	y = 0.5,
--     	width = 0.15,
--     	height = 0.05
--     },
--     {
--     	x = 0.07 + -0.35,
--     	y = 0.5,
--     	width = 0.15,
--     	height = 0.05
--     },
--     {
-- 		x = 0.07 + -0.2,
-- 		y = 0.5,
-- 		width = 0.15,
-- 		height = 0.05,
--         type = "BRICK_OVERTIME"
--     },
--     {
-- 	    x = 0.07 + -0.05,
-- 	    y = 0.5,
-- 	    width = 0.15,
-- 	    height = 0.05,
--         type = "BRICK_OVERTIME"
--     },
--     {
-- 	    x = 0.07 + 0.1,
-- 	    y = 0.5,
-- 	    width = 0.15,
-- 	    height = 0.05
--     },
--     {
--     	x = 0.07 + 0.25,
--     	y = 0.5,
--     	width = 0.15,
--     	height = 0.05
--     },
--     {
--     	x = 0.07 + 0.40,
--     	y = 0.5,
--     	width = 0.15,
--     	height = 0.05
--     },
--     {
--     	x = 0.07 + 0.55,
--     	y = 0.5,
--     	width = 0.15,
--     	height = 0.05,
--         type = "BRICK_INFIN"
--     },
--     {
--     	x = 0.07 + 0.7,
--     	y = 0.5,
--     	width = 0.15,
--     	height = 0.05,
--         type = "BRICK_INFIN"
--     },
-- }
