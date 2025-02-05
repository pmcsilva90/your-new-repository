SELECT
    schools.name,
    per_pupil_expenditure,
    graduated
FROM
    schools
    JOIN graduation_rates ON schools.id = graduation_rates.school_id
    JOIN districts ON schools.district_id = districts.id
    JOIN expenditures ON districts.id = expenditures.district_id
ORDER BY
    per_pupil_expenditure DESC,
    schools.name;
