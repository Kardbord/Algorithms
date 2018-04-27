module PowerOfTwo where

-- Determines if @n is a power of two
--
-- Determines if @n is a power of two by
-- taking advantage of the fact that the
-- log base 2 of any power of two will
-- result in a whole number.
-- Note that this method is inaccurate beyond 2^37
--
-- param n : any number
-- return  : true if @n is a power of two, false if not
poweroftwo :: Integer -> Bool
poweroftwo n = 
    fromIntegral (floor (logBase 2 (fromInteger n)) :: Integer) == (logBase 2 (fromInteger n))

