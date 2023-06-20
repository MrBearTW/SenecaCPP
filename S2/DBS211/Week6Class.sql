





CREATE TABLE w6Transaction (
    
);


CREATE TABLE w6Account (
    
);

ALTER TABLE w6Transaction
ADD CONSTRAINT fk_w6Transaction_w6Account FOREIGN KEY (account_id);

INSERT INTO w6Account VALUES(1, 'Clint', 'C', 5566.56);
INSERT INTO w6Account VALUES(2, 'Clint', 'S', 1234.56);

-- 