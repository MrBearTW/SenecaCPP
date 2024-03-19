import { useEffect } from "react";
import { useForm } from "react-hook-form";

export default function Advanced(){


    const { register, handleSubmit, setValue, watch, formState: { errors } } = useForm({
        defaultValues: {
            userName: "",
            address: "",
            campus: "",
            program: [],
            parking: "",
            age: 0,
            active: false
        },
      });

    useEffect(()=>{
        // pretend that this data is coming from an API
        let data = {
            userName: "Homer Simpson",
            address: "123 Main St, Springfield U.S.A",
            campus: "newnham",
            program: ['CPA', 'CPP'],
            parking: "semester",
            age: 42,
            active: true
          }

          for (const prop in data) {
            setValue(prop, data[prop]);
          }
          
    }, [])

    function submitForm(data){
        console.log(data);
    }

    const watchUserName = watch('userName');

    return ( <>
        <h2>Advanced (React Hook Form)</h2>

        <p>Debug (Watch): User Name: {watchUserName}</p>

        <form onSubmit={handleSubmit(submitForm)}>
            User Name<br />
            <input className={errors.userName && "inputError"} type="text" {...register('userName', {required: true, maxLength: 20 })} />
            {errors.userName?.type === "required" && <span><br />First Name is required</span>}
            {errors.userName?.type === "maxLength" &&<span><br />First Name Cannot contain more than 20 characters</span>}

            <br /><br />

            Age<br />
            <input type="number" {...register("age", {min: 18, max: 99, validate: {onlyEven: v => v % 2 == 0}})} />
            {errors.age?.type === "min" && <span><br />You must be at least 18 years old</span>}
            {errors.age?.type === "max" && <span><br />You must be 99 years old or younger</span>}
            {errors.age?.type === "onlyEven" && <span><br />You must enter an even number</span>}

            <br /><br />

            Address: <br />
            <textarea {...register("address")}></textarea>

            <br /><br />

            Campus: <br />
            <select {...register("campus")}>
                <option value="king">King</option>
                <option value="SatY">Seneca at York</option>
                <option value="newnham">Newnham</option>
                <option value="markham">Markham</option>
            </select>
      
            <br /><br />

            Program: <br />
            <select multiple {...register("program")}>
                <option value="DAD">Database Application Developer</option>
                <option value="CPA">Computer Programming &amp; Analysis</option>
                <option value="CPP">Computer Programming</option>
                <option value="DSA">Honours Bachelor of Data Science and Analytics</option>
            </select>
            
            <br /><br />

            Parking: <br />
            <input type="radio" value="daily" {...register("parking")} /> Daily<br />
            <input type="radio" value="semester" {...register("parking")} /> Semester<br />
            <input type="radio" value="year" {...register("parking")} /> Academic Year

            <br /><br />

            <input type="checkbox" {...register("active")} />Currently Active
            
            <br /><br />

            <button type="submit" disabled={Object.keys(errors).length > 0}>Submit</button>
        </form>
        
    </> )

}