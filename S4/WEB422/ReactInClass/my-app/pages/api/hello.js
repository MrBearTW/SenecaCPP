// Next.js API route support: https://nextjs.org/docs/api-routes/introduction

export default function handler(req, res) {
  const { method } = req;

  switch (method) {
    case 'GET':
      res.status(200).json({ name: 'John Doe' });
      break;
    case 'POST':
      // return the 'name' value provided in the body of the rquest
      res.status(200).json({ name: req.body.name });
      break;
    default:
      // send an error message back, indicating that the method is not supported by this route
      res.setHeader('Allow', ['GET', 'POST']);
      res.status(405).end(`Method ${method} Not Allowed`);
  }
}
