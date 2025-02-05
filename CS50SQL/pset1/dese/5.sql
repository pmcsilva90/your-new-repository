SELECT
    *
FROM
    (
        SELECT
            city,
            COUNT(*) AS "Number of Public Schools"
        FROM
            schools
        WHERE
            type = "Public School"
        GROUP BY
            city
        ORDER BY
            COUNT(*) DESC,
            city
    )
WHERE
    "Number of Public Schools" <= 3;
