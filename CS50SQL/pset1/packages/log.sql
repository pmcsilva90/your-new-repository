
-- *** The Lost Letter ***

-- Find the receiver's address in the addresses table
SELECT * FROM addresses WHERE address = "2 Finnegan Street"; -- this query yields no match


-- Find the sender's address in the address table
SELECT * FROM addresses WHERE address = "900 Somerville Avenue";

-- Find packages sent from sender's address
SELECT * FROM packages WHERE from_address_id = (
SELECT id FROM addresses WHERE address = "900 Somerville Avenue");

-- Given one of the packges contents has the description "Congratulatory letter", it can be assumed to be the lost letter. The query shows it was sent to address ID 854

-- Find the address with ID of 854
SELECT * FROM addresses WHERE id = 854;
-- Query returns address 2 Finnigan Street, which is one character different from Anneke's spelling.

-- Find a package where there is no address from the sender
sqlite> SELECT * FROM packages WHERE from_address_id IS NULL;



-- *** The Devious Delivery ***

-- *** The Forgotten Gift ***

