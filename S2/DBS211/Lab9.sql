-- Add column if necessary

-- UNF:  
Order [CK OrderNo, Orderdate, CustNo, CustLname, (PartNo, PartDesc, QtyOrd, Price)]


-- 1NF:
ORDER [CK OrderNo, Orderdate, CustNo, CustLname, SalesRepNo, SalesLname]
ORDER_PART [PK PartNo, PK FK OrderNo, QtyOrd, Quoted_Price]


-- 2NF:
ORDER [CK OrderNo, Orderdate, CustNo, CustLname, SalesRepNo, SalesLname]
ORDER_PART [PK FK PartNo, PK FK OrderNo, QtyOrd, Quoted_Price]
PART [PK PartNo, PartDesc, MSRP]


-- 3NF:
ORDER [CK OrderNo, Orderdate, FK CustNo, FK SalesRepNo]
ORDER_PART [PK FK PartNo, PK FK OrderNo, QtyOrd, Quoted_Price]
PART [PK PartNo, PartDesc, MSRP, PartCost, PartWeight]
CUSTOMER [PK CustNo, CustLname, CusfEmail, CustPhone]
SALESREP [PK SalesRepNo, SalesLname, SalesEmail, SalesPhone]


